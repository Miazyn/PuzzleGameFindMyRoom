// Fill out your copyright notice in the Description page of Project Settings.


#include "SecretPassageOpen.h"
#include "Math/UnrealMathUtility.h"
#include "Components/AudioComponent.h"
#include "VectorTypes.h"

// Sets default values
ASecretPassageOpen::ASecretPassageOpen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASecretPassageOpen::OpenSecretPassage_Implementation(float DeltaTime)
{
	FRotator CurrentRotator = GetOwner()->GetActorRotation();
	CurrentRotator.Yaw = FMath::Lerp(CurrentRotator.Yaw, TargetYaw, DeltaTime * DoorSpeed);

	GetOwner()->SetActorRotation(CurrentRotator);
}

void ASecretPassageOpen::ErrorMessages()
{
	
}

// Called when the game starts or when spawned
void ASecretPassageOpen::BeginPlay()
{
	Super::BeginPlay();

	StartRotation = GetOwner()->GetActorRotation().Yaw;
	TargetYaw = StartRotation + DoorAngle;
	
	//ErrorMessages();
}

// Called every frame
void ASecretPassageOpen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

