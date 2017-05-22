package main

import "testing"

func TestImplement_hello(t *testing.T) {
	tests := []struct {
		name      string
		implement Implement
	}{
	// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			tt.implement.hello()
		})
	}
}
