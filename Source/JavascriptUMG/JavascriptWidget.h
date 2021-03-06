#pragma once

#include "UserWidget.h"
#include "JavascriptWidget.generated.h"

class UJavascriptWidget;
class UJavascriptContext;

/**
 * 
 */
UCLASS()
class JAVASCRIPTUMG_API UJavascriptWidget : public UUserWidget
{
	GENERATED_UCLASS_BODY()

public:	
	UPROPERTY(BlueprintReadWrite, Category = "Javascript")
	UJavascriptContext* JavascriptContext;

	UFUNCTION(BlueprintCallable, Category = "Scripting | Javascript")
	void SetRootWidget(UWidget* Widget);	

	virtual void ProcessEvent(UFunction* Function, void* Parms) override;

	UFUNCTION(BlueprintCallable, Category = "Scripting | Javascript")
	static void CallSynchronizeProperties(UVisual* WidgetOrSlot);	

	UFUNCTION(BlueprintCallable, Category = "Scripting | Javascript")
	static bool HasValidCachedWidget(UWidget* Widget);	

	UFUNCTION(BlueprintCallable, Category = "Scripting | Javascript")
	UPanelSlot* AddChild(UWidget* Content);

	UFUNCTION(BlueprintCallable, Category = "Scripting | Javascript")
	bool RemoveChild();

	UFUNCTION(BlueprintCallable, Category = "Scripting | Javascript")
	void OnListenForInputAction(FName ActionName, TEnumAsByte< EInputEvent > EventType, bool bConsume);

	UFUNCTION(BlueprintImplementableEvent, Category = "Scripting | Javascript")
	void OnInputActionByName(FName ActionName);

protected:

	UPROPERTY()
	UPanelSlot* ContentSlot;

protected:

	virtual UClass* GetSlotClass() const
	{
		return UPanelSlot::StaticClass();
	}

	virtual void OnSlotAdded(UPanelSlot* Slot)
	{

	}

	virtual void OnSlotRemoved(UPanelSlot* Slot)
	{

	}
};