#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDMGProjectile.generated.h"

UCLASS()
class TDMG_API ATDMGProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATDMGProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
