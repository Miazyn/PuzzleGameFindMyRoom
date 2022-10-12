// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

#include "Microsoft/AllowMicrosoftPlatformTypes.h"

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	

}


void UGrabber::BeginPlay()
{
	Super::BeginPlay();

    FindPhysicsHandle();
	InputSetup();
	
}


void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(MyPhysicsHandle->GrabbedComponent)
	{
		MyPhysicsHandle->SetTargetLocation(GetLineTraceEnd());
	}
}


void UGrabber::Grab() {

	UE_LOG(LogTemp, Warning, TEXT("Grab."));

	FHitResult Hit = GetFirstBodyInReach();

	if(Hit.GetComponent() && MyPhysicsHandle)
	{
		MyPhysicsHandle->GrabComponentAtLocation(Hit.GetComponent(), NAME_None, GetLineTraceEnd());
		UE_LOG(LogTemp, Warning, TEXT("Component grabbed"));
	}
	
}

void UGrabber::GrabRelease() {

	UE_LOG(LogTemp, Warning, TEXT("Grab released."));
	if(MyPhysicsHandle->GrabbedComponent)
	{
		MyPhysicsHandle->ReleaseComponent();
	}
}

void UGrabber::FindPhysicsHandle()
{
	MyPhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (!MyPhysicsHandle) 
	{
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle is missing."));

	}
}

void UGrabber::InputSetup()
{
	MyInputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (MyInputComponent) 
	{
		MyInputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		MyInputComponent->BindAction("Grab", IE_Released, this, &UGrabber::GrabRelease);
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("MyInputComponent is missing."));
	}
}

FHitResult UGrabber::GetFirstBodyInReach()
{
	FVector PlayerViewpointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewPointRotation);

	FVector LineTraceEnd = PlayerViewpointLocation + PlayerViewPointRotation.Vector() * TraceLength;

	DrawDebugLine(GetWorld(), PlayerViewpointLocation, LineTraceEnd, FColor(0,255,0), false, 0.f,0, 5.f);

	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(OUT Hit, PlayerViewpointLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),TraceParams);

	AActor* ActorHited = Hit.GetActor();
	if (ActorHited) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor: %s"), *ActorHited->GetName());
	}
	return Hit;
}

FVector UGrabber::GetLineTraceEnd()
{
	FVector PlayerViewpointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewpointLocation, OUT PlayerViewPointRotation);

	FVector LineTraceEnd = PlayerViewpointLocation + PlayerViewPointRotation.Vector() * TraceLength;
	return  LineTraceEnd;
}


