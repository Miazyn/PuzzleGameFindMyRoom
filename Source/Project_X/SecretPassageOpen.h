// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"

#include "SecretPassageOpen.generated.h"

UCLASS()
class PROJECT_X_API ASecretPassageOpen : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecretPassageOpen();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyFunctions")
	void OpenSecretPassage(float DeltaTime);

	UPROPERTY(EditAnywhere)
	float TargetYaw;

	UPROPERTY(VisibleAnywhere)
	float StartRotation;

	UPROPERTY(EditAnywhere)
	float DoorAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	float DoorSpeed = 1.0f;

	void ErrorMessages();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
