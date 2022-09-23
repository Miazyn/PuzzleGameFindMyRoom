// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	
	MyPhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (!MyPhysicsHandle) {
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle is missing."));

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Works."));
	}

	MyInputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (MyInputComponent) {
		MyInputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		MyInputComponent->BindAction("Grab", IE_Released, this, &UGrabber::GrabRelease);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("MyInputComponent is missing."));
		
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	FVector PlayerViewpointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewPointRotation);

	//UE_LOG(LogTemp, Warning, TEXT("Location %s | Rotation %s"), *PlayerViewpointLocation.ToString(), *PlayerViewPointRotation.ToString());

	FVector LineTraceEnd = PlayerViewpointLocation + PlayerViewPointRotation.Vector() * TraceLength;

	DrawDebugLine(GetWorld(), PlayerViewpointLocation, LineTraceEnd, FColor(0,255,0), false, 0.f,0, 5.f);

	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(OUT Hit, PlayerViewpointLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),TraceParams);

	AActor* ActorHitted = Hit.GetActor();
	if (ActorHitted) {
		UE_LOG(LogTemp, Warning, TEXT("Actor: %s"), *ActorHitted->GetName());
	}
}


void UGrabber::Grab() {

	UE_LOG(LogTemp, Warning, TEXT("Grab."));
}

void UGrabber::GrabRelease() {

	UE_LOG(LogTemp, Warning, TEXT("Grab released."));
}

