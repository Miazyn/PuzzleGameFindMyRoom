// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_X_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrabber();
	UPROPERTY(EditAnywhere)
		float TraceLength = 200.f;

	UPhysicsHandleComponent* MyPhysicsHandle = nullptr;

	UInputComponent* MyInputComponent = nullptr;

	void Grab();
	void GrabRelease();
	void FindPhysicsHandle();
	void InputSetup();
	FHitResult GetFirstBodyInReach();
	FVector GetLineTraceEnd();
	

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
