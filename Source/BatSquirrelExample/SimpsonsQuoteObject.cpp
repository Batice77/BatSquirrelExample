// Copyright 2020 - Florent WASSEN

#include "SimpsonsQuoteObject.h"
#include "SimpsonsQuoteClass.h"
#include "SimpsonsVM.h"

USimpsonsQuoteObject::USimpsonsQuoteObject()
{
    SquirrelClass = USimpsonsQuoteClass::StaticClass();
}

void USimpsonsQuoteObject::Constructor(FSquirrelValue Table)
{
    if(Table.GetType() != ESquirrelValueType::Table) return;

    // Extract datas from the table
    Quote = Table.GetSlot("quote").ToString();
    CharacterName = Table.GetSlot("character").ToString();
    CharacterDirection = Table.GetSlot("characterDirection").ToString();
    ImageURL = Table.GetSlot("image").ToString();
}

void USimpsonsQuoteObject::SetImage(FSquirrelValue ImageData)
{
    Image = USimpsonsVM::ArrayUInt8ToTexture(ImageData.ToBytes());
}