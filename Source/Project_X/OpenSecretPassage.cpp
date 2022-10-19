// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenSecretPassage.h"

// Sets default values for this component's properties
UOpenSecretPassage::UOpenSecretPassage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UOpenSecretPassage::OpenSecretPassage_Implementation(float DeltaTime)
{
	FRotator CurrentRotator = GetOwner()->GetActorRotation();
	CurrentRotator.Yaw = FMath::Lerp(CurrentRotator.Yaw, TargetYaw, DeltaTime * DoorSpeed);

	GetOwner()->SetActorRotation(CurrentRotator);
}


// Called when the game starts
void UOpenSecretPassage::BeginPlay()
{
	Super::BeginPlay();

	StartRotation = GetOwner()->GetActorRotation().Yaw;
	TargetYaw = StartRotation + DoorAngle;
	
}


// Called every frame
void UOpenSecretPassage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

