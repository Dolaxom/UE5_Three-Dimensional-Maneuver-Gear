#include "TDMGProjectile.h"

// Sets default values
ATDMGProjectile::ATDMGProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATDMGProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATDMGProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

