// Copyright 2020 - Florent WASSEN

#include "SimpsonsQuoteClass.h"
#include "SimpsonsQuoteObject.h"

USimpsonsQuoteClass::USimpsonsQuoteClass()
{
    ClassName = "SimpsonsQuote";
    ObjectClass = USimpsonsQuoteObject::StaticClass();

    StaticMembers.Add("constructor", FSquirrelValue(GET_FUNCTION_NAME_CHECKED(USimpsonsQuoteObject, Constructor)));
    StaticMembers.Add("quote", FSquirrelValue(GET_MEMBER_NAME_CHECKED(USimpsonsQuoteObject, Quote), nullptr, true));
    StaticMembers.Add("characterName", FSquirrelValue(GET_MEMBER_NAME_CHECKED(USimpsonsQuoteObject, CharacterName), nullptr, true));
    StaticMembers.Add("imageURL", FSquirrelValue(GET_MEMBER_NAME_CHECKED(USimpsonsQuoteObject, ImageURL), nullptr, true));
    StaticMembers.Add("characterDirection", FSquirrelValue(GET_MEMBER_NAME_CHECKED(USimpsonsQuoteObject, CharacterDirection), nullptr, true));
    
    StaticMembers.Add("setImage", FSquirrelValue(GET_FUNCTION_NAME_CHECKED(USimpsonsQuoteObject, SetImage)));
}