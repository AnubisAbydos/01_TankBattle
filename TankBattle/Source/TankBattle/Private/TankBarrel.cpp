// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankBarrel.h"



void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// move barrel right amount this frame given max speed
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate Called at speed %f"), DegreesPerSecond);
}
