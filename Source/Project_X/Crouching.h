// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Crouching.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_X_API UCrouching : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCrouching();

	UInputComponent* MyInputComponent = nullptr;

	void InputSetup();
	void CrouchDown();
	void CrouchUp();

	UPROPERTY(VisibleAnywhere)
	AActor* ActorToCrouch;

	FVector ActorLocation;
	FVector newLocation;

	UPROPERTY(EditAnywhere)
	float goDownValue = 5;

	UPROPERTY(VisibleAnywhere)
	bool currentlyCrouched = false;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
		
};
