// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpen.h"

#include "VectorTypes.h"

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

	StartRotation = GetOwner()->GetActorRotation().Yaw;
	TargetYaw = StartRotation + DoorAngle;
	

	ActorToOpenDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!TriggerVolumeToOpenDoor)
	{
		UE_LOG(LogTemp, Error, TEXT("Achtung: Trigger wurde nicht gesetzt!"));
	}

	if (!ActorToOpenDoor)
	{
		UE_LOG(LogTemp, Error, TEXT("Achtung: Actor wurde nicht gesetzt!"));
	}

	
	//TriggerVolumeToOpenDoor->GetOverlappingActors(TriggerVolumeToOpenDoor.GetActor);

	//UE_LOG(LogTemp, Error, TEXT("%s"), *Door.ToCompactString());
}


// Called every frame
void UDoorOpen::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (TriggerVolumeToOpenDoor
		&& (TriggerVolumeToOpenDoor->IsOverlappingActor(ActorToOpenDoor)|| GetTotalMassOfActors() > TargetWeight)) 
	{
		OpenDoorNow(DeltaTime);
		DoorLastOpen = GetWorld()->GetTimeSeconds();
	}
	else if((GetWorld()->GetTimeSeconds() - DoorLastOpen) > DoorCloseDelay)
	{
		CloseDoor(DeltaTime);
	}
		
	
	
	
	
}



void UDoorOpen::OpenDoorNow(float DeltaTime)
{
		FRotator CurrentRotator = GetOwner()->GetActorRotation();
		CurrentRotator.Yaw = FMath::Lerp(CurrentRotator.Yaw, TargetYaw, DeltaTime * DoorSpeed);

		GetOwner()->SetActorRotation(CurrentRotator);
	
}

void UDoorOpen::CloseDoor(float DeltaTime)
{
	FRotator CurrentRotator = GetOwner()->GetActorRotation();
	CurrentRotator.Yaw = FMath::Lerp(CurrentRotator.Yaw, StartRotation, DeltaTime * DoorSpeed);


	GetOwner()->SetActorRotation(CurrentRotator);

	

}

float UDoorOpen::GetTotalMassOfActors()
{

	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors;
	TriggerVolumeToOpenDoor->GetOverlappingActors(OUT OverlappingActors);

	for(AActor* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass;
}

