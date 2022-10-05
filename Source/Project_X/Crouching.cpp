// Fill out your copyright notice in the Description page of Project Settings.


#include "Crouching.h"
#include "GameFramework/Actor.h"

UCrouching::UCrouching()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCrouching::BeginPlay()
{
	Super::BeginPlay();

	ActorToCrouch = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ActorToCrouch) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Actor defined"));
	}
	InputSetup();
	
}


void UCrouching::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCrouching::InputSetup() 
{

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
}

void UCrouching::CrouchDown() 
{
	ActorLocation = ActorToCrouch->GetActorLocation();
	newLocation = FVector(ActorLocation.X, ActorLocation.Y , ActorLocation.Z- goDownValue);
	ActorToCrouch->SetActorLocation(newLocation, false);

	currentlyCrouched = !currentlyCrouched;
	UE_LOG(LogTemp, Warning, TEXT("Clicked to crouch."));

}
void UCrouching::CrouchUp() 
{

	currentlyCrouched = !currentlyCrouched;
	UE_LOG(LogTemp, Warning, TEXT("Released Crouch"));

}


