package main

import (
	"fmt"
	"sort"
)

type NumSort struct {
	n int
}

func (ns NumSort) String() string {
	return fmt.Sprintf("%d", ns.n)
}

type ByNum []NumSort

func (a ByNum) Len() int           { return len(a) }
func (a ByNum) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByNum) Less(i, j int) bool { return a[i].n > a[j].n }

func main() {
	nums := []int{5, 4, 3, 2, 1}
	bn := make(ByNum, len(nums))
	for i, v := range nums {
		bn[i] = NumSort{n: v}
	}
	fmt.Println(bn)
	sort.Sort(ByNum(bn))
	fmt.Println(bn)

}
