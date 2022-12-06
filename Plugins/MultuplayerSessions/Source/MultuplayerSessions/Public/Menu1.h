// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu1.generated.h"

/**
 * 
 */
UCLASS()
class MULTUPLAYERSESSIONS_API UMenu1 : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections =4,FString TypeOfMatch=FString(TEXT("FreeForAll")));
protected:
	virtual bool Initialize() override;
	//在一个关卡即将被GC时调用
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

	//用于MultiPlayer类的回调函数
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SearchResults,bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);
	
private:
	UPROPERTY(meta=(BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta=(BindWidget))
	UButton* JoinButton;
	UFUNCTION()
	void HostButtonClicked();
	UFUNCTION()
	void JoinButtonClicked();

	//引入封装的multiplayersunsystem类
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	void MenuTearDown();

	int32 NumOfPublicConnections{4};
	FString MatchType{FString(TEXT("FreeForAll"))};
};
