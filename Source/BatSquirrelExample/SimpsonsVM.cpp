// Copyright 2020 - Florent WASSEN

#include "SimpsonsVM.h"

#include "HttpModule.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "SimpsonsQuoteClass.h"
#include "SimpsonsQuoteObject.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/IHttpResponse.h"
#include "Engine/Texture2D.h"

USimpsonsVM::USimpsonsVM()
{
    ClassToRegister.Add(USimpsonsQuoteClass::StaticClass());
    
    RootTable.Add("httpGet", FSquirrelValue(GET_FUNCTION_NAME_CHECKED(USimpsonsVM, HttpGet)));
    RootTable.Add("addQuoteToWidget", FSquirrelValue(GET_FUNCTION_NAME_CHECKED(USimpsonsVM, AddQuoteToWidget)));
}

void USimpsonsVM::HttpGet(FString Url, FSquirrelValue SuccessCallback, FSquirrelValue ErrorCallback)
{
    FHttpModule* Http = &FHttpModule::Get();
    TSharedRef<IHttpRequest> HttpRequest = Http->CreateRequest();
    HttpRequest->OnProcessRequestComplete().BindLambda([this, SuccessCallback, ErrorCallback](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
    {
        if(bSuccess)
        {
            FSquirrelValue SuccessFunc = SuccessCallback;
            FromSquirrelValue(SuccessFunc);
            PushRootTable(); // This
            FSquirrelValue Content;
            if(Response->GetContentType().EndsWith("utf-8")) Content = FSquirrelValue(Response->GetContentAsString());
            else Content = FSquirrelValue(Response->GetContent());
            FromSquirrelValue(Content);
            Call(2);
            Pop(); // Pop SuccessFunc
        }
        else
        {
            FSquirrelValue ErrorFunc = ErrorCallback;
            FromSquirrelValue(ErrorFunc);
            PushRootTable(); // This
            Call(1);
            Pop(); // Pop ErrorFunc
        }
    });
    HttpRequest->SetVerb("GET");
    HttpRequest->SetURL(Url);
    HttpRequest->ProcessRequest();
}

UTexture2D* USimpsonsVM::ArrayUInt8ToTexture(TArray<uint8> Array)
{
    IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
    TArray<uint8> Bytes = Array;

    EImageFormat ImageFormat = ImageWrapperModule.DetectImageFormat(Bytes.GetData(), Bytes.Num());
    if (ImageFormat == EImageFormat::Invalid)
    {
        UE_LOG(LogBatSquirrel, Error, TEXT("Format not valid"));
        return nullptr;
    }
    TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ImageFormat);
    if (!ImageWrapper.IsValid())
    {
        UE_LOG(LogBatSquirrel, Error, TEXT("ImageWrapper not valid"));
        return nullptr;
    }
    if (!ImageWrapper->SetCompressed(Bytes.GetData(), Bytes.Num()))
    {
        UE_LOG(LogBatSquirrel, Error, TEXT("Unable to parse image data"));
        return nullptr;
    }

    TArray<uint8> UncompressedBytes;
    if (!ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBytes))
    {
        UE_LOG(LogBatSquirrel, Error, TEXT("Unable to get raw image data"));
        return nullptr;
    }

    Bytes = UncompressedBytes;

    UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), EPixelFormat::PF_B8G8R8A8);
    if (!Texture)
        return nullptr;

    FTexture2DMipMap& Mip = Texture->PlatformData->Mips[0];
    void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
    FMemory::Memcpy(Data, Bytes.GetData(), Bytes.Num());
    Mip.BulkData.Unlock();
    Texture->UpdateResource();

    return Texture;
}

void USimpsonsVM::SetPageWidget(UUserWidget* Widget)
{
    PageWidget = Widget;
}

void USimpsonsVM::AddQuoteToWidget(FSquirrelValue SimpsonsQuote)
{
    if(!PageWidget) return;

    USimpsonsQuoteObject* SimpsonsQuoteObject = Cast<USimpsonsQuoteObject>(SimpsonsQuote.ToObject());

    if(!SimpsonsQuoteObject) return;
    
    UFunction* Func = PageWidget->FindFunction(TEXT("AddQuote"));
    if (Func)
    {
        FTimerDelegate Delegate;
        Delegate.BindUFunction(PageWidget, TEXT("AddQuote"), SimpsonsQuoteObject);
        Delegate.Execute();
    }
}