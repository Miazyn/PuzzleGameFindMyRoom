// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();
    
	FString MeinLog = TEXT("Ich bin ein Text!");
	FString* MeinLogZeiger = &MeinLog;

	/*float Speed = 10.0f;
	FString FloatToSpring = ;*/

	//ToCompactString()
	FString Name = GetOwner()->GetName();
	FVector WorldPos = GetOwner()->GetActorLocation();


	//UE_LOG(LogTemp, Warning, TEXT("Hello Welt"));
	//UE_LOG(LogTemp, Error, TEXT("Hello Welt"));
	/*UE_LOG(LogTemp, Error, TEXT("Mein Text:  %s"), **MeinLogZeiger);
	UE_LOG(LogTemp, Warning, TEXT("Name:  %s"), *Name);*/
	UE_LOG(LogTemp, Warning, TEXT("%s"), *WorldPos.ToCompactString());
	
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

