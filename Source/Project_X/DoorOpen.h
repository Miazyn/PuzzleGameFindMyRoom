// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Components/PrimitiveComponent.h"
#include "DoorOpen.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_X_API UDoorOpen : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorOpen();

	UPROPERTY(EditAnywhere)
	float TargetYaw;

	UPROPERTY(EditAnywhere)
	float TargetWeight = 50;
	
	UPROPERTY(VisibleAnywhere)
	float StartRotation;

	UPROPERTY(EditAnywhere)
	float DoorAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	float DoorSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 2.0f;

	UPROPERTY(VisibleAnywhere)
	float DoorLastOpen;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* TriggerVolumeToOpenDoor;
	UPROPERTY(EditAnywhere)
	AActor* ActorToOpenDoor;

	void OpenDoorNow(float DeltaTime);

	void CloseDoor(float DeltaTime);

	float GetTotalMassOfActors();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
