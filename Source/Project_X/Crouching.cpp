// Fill out your copyright notice in the Description page of Project Settings.


#include "Crouching.h"
#include "Math/TransformNonVectorized.h"
#include "GameFramework/Actor.h"

UCrouching::UCrouching()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCrouching::BeginPlay()
{
	Super::BeginPlay();

	InputSetup();
}


void UCrouching::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCrouching::InputSetup()
{
	myCapsule = GetOwner()->FindComponentByClass<UCapsuleComponent>();
	MyInputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (MyInputComponent)
	{
		MyInputComponent->BindAction("Crouch", IE_Pressed, this, &UCrouching::CrouchDown);
		MyInputComponent->BindAction("Crouch", IE_Released, this, &UCrouching::CrouchUp);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MyInputComponent is missing."));
	}
	if (!myCapsule)
	{
		UE_LOG(LogTemp, Error, TEXT("My Capsule Component is missing."));
	}
}

void UCrouching::CrouchDown() 
{
	currentScale = myCapsule->GetScaledCapsuleHalfHeight();
	myCapsule->SetCapsuleHalfHeight(currentScale-goDownValue, true);
	UE_LOG(LogTemp, Warning, TEXT("Clicked to crouch."));

}
void UCrouching::CrouchUp() 
{
	currentScale = myCapsule->GetScaledCapsuleHalfHeight();
	myCapsule->SetCapsuleHalfHeight(currentScale +goDownValue, true);
	UE_LOG(LogTemp, Warning, TEXT("Released Crouch"));

}


