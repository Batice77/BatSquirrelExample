// Copyright 2020 - Florent WASSEN

#pragma once

#include "CoreMinimal.h"
#include "SquirrelClassObject.h"
#include "SimpsonsQuoteObject.generated.h"

UCLASS()
class BATSQUIRRELEXAMPLE_API USimpsonsQuoteObject : public USquirrelClassObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FString Quote;
	UPROPERTY(BlueprintReadOnly)
	FString CharacterName;
	UPROPERTY(BlueprintReadOnly)
	FString ImageURL;
	UPROPERTY(BlueprintReadOnly)
	FString CharacterDirection;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* Image;
	
	USimpsonsQuoteObject();

	UFUNCTION()
	void Constructor(FSquirrelValue Table);

	UFUNCTION()
	void SetImage(FSquirrelValue ImageData);
};