package main

import "fmt"

//Hello interface
type Hello interface {
	hello()
}

//Implement of Hello interface
type Implement struct {
	myWords string
	Hello
}

//implement of Hello interface method
func (implement Implement) hello() {
	fmt.Println("Hello " + implement.myWords + "\n")
}

func main() {
	i := Implement{myWords: "Golang!"}
	i.hello()
}
