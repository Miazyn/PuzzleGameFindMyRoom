// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpen.h"

// Sets default values for this component's properties
UDoorOpen::UDoorOpen()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpen::BeginPlay()
{
	Super::BeginPlay();

	FRotator StartRotation = GetOwner()->GetActorRotation();

	YawBack = StartRotation.Yaw;
	TargetYaw = StartRotation.Yaw += 90;
	
	
	OpenTheDoorActor = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!MyTriggerVolume)
	{

		UE_LOG(LogTemp, Error, TEXT("Trigger volume has not been set"));

	}
	
	if (!OpenTheDoorActor)
	{

		UE_LOG(LogTemp, Error, TEXT("Actor has not been set"));

	}
	

	//UE_LOG(LogTemp, Error, TEXT("%s"), *Door.ToCompactString());
}


// Called every frame
void UDoorOpen::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (MyTriggerVolume && MyTriggerVolume->IsOverlappingActor(OpenTheDoorActor)) 
	{
		OpenDoorNow(DeltaTime);
		DoorLastOpen = GetWorld()->GetTimeSeconds();
	}
	else if(GetWorld()->GetTimeSeconds() - DoorLastOpen > DoorCloseTime)
	{
		CloseDoorNow(DeltaTime);
	}
	
}

void UDoorOpen::OpenDoorNow(float DeltaTime)
{
	FRotator CurrentRotator = GetOwner()->GetActorRotation();
	CurrentRotator.Yaw = FMath::Lerp(CurrentRotator.Yaw, TargetYaw, DeltaTime * speed);

	GetOwner()->SetActorRotation(CurrentRotator);
}

void UDoorOpen::CloseDoorNow(float DeltaTime)
{
	
	FRotator CurrentRotator = GetOwner()->GetActorRotation();
	CurrentRotator.Yaw = FMath::Lerp(CurrentRotator.Yaw, YawBack, DeltaTime * speed);

	GetOwner()->SetActorRotation(CurrentRotator);
}


