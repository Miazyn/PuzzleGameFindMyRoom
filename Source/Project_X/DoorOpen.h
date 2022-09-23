// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "DoorOpen.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_X_API UDoorOpen : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorOpen();


	UPROPERTY(EditAnywhere)
		float speed = 1.02;
	UPROPERTY(EditAnywhere)
		float DoorCloseTime = 2.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* MyTriggerVolume;
	UPROPERTY(VisibleAnywhere)
		AActor* OpenTheDoorActor;

	float YawBack;
	float DoorLastOpen;
	float TargetYaw;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoorNow(float DeltaTime);
	void CloseDoorNow(float DeltaTime);
		
};
