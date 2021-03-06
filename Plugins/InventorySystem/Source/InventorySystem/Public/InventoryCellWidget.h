// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "InventoryData.h"
#include "Blueprint/UserWidget.h"
#include "InventoryCellWidget.generated.h"

class UImage;
class UTextBlock;
class UInventoryCellWidget;
class UInventoryWidget;


UCLASS()
class INVENTORYSYSTEM_API UInventoryCellWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(BlueprintReadOnly, Meta=(BindWidget))
	UTextBlock * CountText;
	UPROPERTY(BlueprintReadOnly, Meta=(BindWidget))
	UTextBlock * NameText;
	UPROPERTY(BlueprintReadOnly, Meta=(BindWidget))
	UImage * ItemImage;
	UPROPERTY()
	UTexture2D* TextureForDrag;
	UPROPERTY()
	FInventorySlotInfo Item;
	UPROPERTY()
	UInventoryWidget * ParentInventoryWidget;
	
	bool bHasItem;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	UPROPERTY(EditAnywhere)
	bool bCanDrop = true;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryCellWidget> DragWidgetClass;

public:
	UPROPERTY(EditAnywhere)
	int32 IndexInInventory = INDEX_NONE;
	
	bool AddItem(const FInventorySlotInfo & InSlot, const FInventoryItemInfo & Info);
	const FInventorySlotInfo & GetItem() const {return Item;}
	bool HasItem() const {return bHasItem;}
	void Clear();
	
	FOnItemDrop OnItemDrop;

	UFUNCTION()
	UInventoryComponent * GetParentInventory() const;
	UFUNCTION()
	void SetParentInventoryWidget(UInventoryWidget * InParentWidget);
};
