// Copyright Silent Neon (Lex Hall)

#include "TankBattle.h"
#include "TankBarrel.h"



void UTankBarrel::Elevate(float RelativeSpeed)
{
	// move barrel right amount this frame given max speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
