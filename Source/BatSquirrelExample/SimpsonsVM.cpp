// Copyright 2020 - Florent WASSEN

#include "SimpsonsVM.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

USimpsonsVM::USimpsonsVM()
{
    RootTable.Add("httpGet", FSquirrelValue(GET_FUNCTION_NAME_CHECKED(USimpsonsVM, HttpGet)));
}

void USimpsonsVM::HttpGet(FString Url, FSquirrelValue SuccesCallback, FSquirrelValue ErrorCallback)
{
    FHttpModule* Http = &FHttpModule::Get();
    TSharedRef<IHttpRequest> HttpRequest = Http->CreateRequest();
    HttpRequest->OnProcessRequestComplete().BindLambda([this, SuccesCallback, ErrorCallback](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
    {
        if(bSuccess)
        {
            FSquirrelValue SuccessFunc = SuccesCallback;
            FromSquirrelValue(SuccessFunc);
            PushRootTable(); // This // Replace it
            FSquirrelValue ContentString = FSquirrelValue(Response->GetContentAsString());
            FromSquirrelValue(ContentString);
            Call(2, nullptr);  // Change it
            Pop(); // Pop SuccessFunc
        }
        else
        {
            FSquirrelValue ErrorFunc = ErrorCallback;
            FromSquirrelValue(ErrorFunc);
            PushRootTable(); // This // Replace it
            Call(1, nullptr); // Change it
            Pop(); // Pop ErrorFunc
        }
    });
    HttpRequest->SetVerb("GET");
    HttpRequest->SetURL(Url);
    HttpRequest->ProcessRequest();
}
