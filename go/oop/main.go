package main

import "fmt"

//Hello interface
type Hello interface {
	hello()
}

//Implement of Hello interface
type Implement struct {
	myWords string
}

//implement of Hello interface method
func (implement Implement) hello() {
	fmt.Println("Hello " + implement.myWords + "\n")
}

//Protol type of Hello
type Protol struct {
	helloImplement Hello
}

func main() {
	i := Implement{"Golang!"}
	obj := Protol{i}
	obj.helloImplement.hello()
}
