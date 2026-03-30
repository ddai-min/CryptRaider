// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Trigger();

	UFUNCTION(BlueprintCallable)
	void Grab();

private:
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance = 400;

	void PrintDamage(float Damage);

	void PrintDamageRef(float& Damage);

	void PrintDamageConstRef(const float& Damage);

	// Out Parameter (출력 매개변수)
	// 출력용으로 사용할 목적의 매개변수
	// 힌트를 주기 위해 변수의 앞에 'Out'을 붙인다.
	bool HasDamage(float& OutDamage);

	UPROPERTY(EditAnywhere)
	float GrabRadius = 100;
};
