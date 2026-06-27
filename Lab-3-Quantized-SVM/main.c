/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "svm_model_q.h"
#include "scaler_q.h"
#include "test_images_q.h"


void scale_input(int8_t *x){
	for (int i = 0; i < NUM_FEATURES; i++){
		x[i] = (x[i] - (mean[i]*mean_scale)) / (scale[i]*scale_scale);
	}
}

float predict(int8_t *x){
	int best_class = 0;
	float max_score = -INFINITY;
	for (int c = 0; c < NUM_CLASSES; ++c){
		float score = bias[c] * bias_scale;
		for (int i = 0; i < NUM_FEATURES; i++){
			score += weights[c][i] * x[i] * weight_scale;
		}

		if (score > max_score){
			max_score = score;
			best_class = c;
		}
	}
	return best_class;
}

void print_float(float val){
	int int_part = (int)val;
	int frac_part = (int)((val - int_part)*100);
	if (frac_part < 0) frac_part *= -1;
	printf("%d.%02d \n", int_part, frac_part);
}


int main(){
	for (int i = 0; i < NUM_IMAGES; i++){
		scale_input(test_images[i]);
		int predicted = predict(test_images[i]);
		int actual = test_labels[i];
		printf("Image %d: Predicted = %d, Actual = %d\n", i, predicted, actual);
	}
}