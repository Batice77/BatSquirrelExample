// Copyright 2020 - Florent WASSEN

#pragma once

#include "CoreMinimal.h"
#include "SquirrelVM.h"
#include "SimpsonsVM.generated.h"

/**
 * 
 */
UCLASS()
class BATSQUIRRELEXAMPLE_API USimpsonsVM : public USquirrelVM
{
	GENERATED_BODY()
public:
	USimpsonsVM();

	UPROPERTY()
	UUserWidget* PageWidget;

	UFUNCTION()
	void HttpGet(FString Url, FSquirrelValue SuccessCallback, FSquirrelValue ErrorCallback);
	
	static UTexture2D* ArrayUInt8ToTexture(TArray<uint8> Array);

	UFUNCTION(BlueprintCallable)
	void SetPageWidget(UUserWidget* Widget);
	
	UFUNCTION()
	void AddQuoteToWidget(FSquirrelValue SimpsonsQuote);
};