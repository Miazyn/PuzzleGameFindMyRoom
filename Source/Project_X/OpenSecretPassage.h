// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenSecretPassage.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_X_API UOpenSecretPassage : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenSecretPassage();
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
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
