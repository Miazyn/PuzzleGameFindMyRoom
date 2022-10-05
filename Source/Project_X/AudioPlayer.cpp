// Fill out your copyright notice in the Description page of Project Settings.

#include "AudioPlayer.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"


// Sets default values for this component's properties
UAudioPlayer::UAudioPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAudioPlayer::BeginPlay()
{
	Super::BeginPlay();
	MyAudio = GetOwner()->FindComponentByClass<UAudioComponent>();

	if (!MyAudio) {
		UE_LOG(LogTemp, Error, TEXT("Missing audio component"));
	}

	
}


// Called every frame
void UAudioPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

