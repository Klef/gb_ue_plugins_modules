// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryChoiseWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void UInventoryChoiseWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (OneButton)
	{
		OneButton->OnClicked.AddDynamic(this, &UInventoryChoiseWidget::OnClickOne);
	}
	if (TwoButton)
	{
		TwoButton->OnClicked.AddDynamic(this, &UInventoryChoiseWidget::OnClickTwo);
	}
	if (ThreeButton)
	{
		ThreeButton->OnClicked.AddDynamic(this, &UInventoryChoiseWidget::OnClickThree);
	}
}


void UInventoryChoiseWidget::OnClickOne()
{
	//OnChoiceCharacter->Broadcast(LoadObject<FInventorySlotInfo>(NULL, UTF8_TO_TCHAR("DataTable'/Game/Widget/Inventory/DA_PreSetDefault'")));
}

void UInventoryChoiseWidget::OnClickTwo()
{
	//OnChoiceCharacter->Broadcast(LoadObject<FInventorySlotInfo>(NULL, UTF8_TO_TCHAR("DataTable'/Game/Widget/Inventory/DA_PreSetRich'")));
}

void UInventoryChoiseWidget::OnClickThree()
{
	//OnChoiceCharacter->Broadcast(LoadObject<FInventorySlotInfo>(NULL, UTF8_TO_TCHAR("DataTable'/Game/Widget/Inventory/DA_PreSetBrick'")));
}


