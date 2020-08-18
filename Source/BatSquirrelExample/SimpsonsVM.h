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

	UFUNCTION()
	void HttpGet(FString Url, FSquirrelValue SuccesCallback, FSquirrelValue ErrorCallback);
};
