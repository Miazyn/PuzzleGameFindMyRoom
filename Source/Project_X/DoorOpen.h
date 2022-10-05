// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Components/PrimitiveComponent.h"

#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"

#include "DoorOpen.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_X_API UDoorOpen : public UActorComponent
{
	GENERATED_BODY()

public:	
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

	UPROPERTY(EditAnywhere)
	UAudioComponent* MyAudio = nullptr;

	void OpenDoorNow(float DeltaTime);

	void CloseDoor(float DeltaTime);

	void PlayAudioDoor();

	void ErrorMessages();

	float GetTotalMassOfActors();

	bool IsDoorOpen = false;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
