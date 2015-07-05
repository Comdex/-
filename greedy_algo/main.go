package main

import (
	"log"
	"time"
)

func main() {

	prob := KnapsackProblem{
		Objects: []*Object{
			&Object{35, 10, 0},
			&Object{30, 40, 0},
			&Object{60, 30, 0},
			&Object{50, 50, 0},
			&Object{40, 35, 0},
			&Object{10, 40, 0},
			&Object{25, 30, 0},
		},
		totalC: 150,
	}

	GreedyAlgo(&prob, Choosefunc1)
}

type Object struct {
	weight int
	price  int
	status int // 0:未选中；1:已选中；2:已经不可选
}

type KnapsackProblem struct {
	Objects []*Object
	totalC  int
}

func GreedyAlgo(problem *KnapsackProblem, spFunc func([]*Object, int) int) {
	var idx, ntc int = 0, 0

	time.Sleep(2 * time.Second)

	// spFunc 每次选最符合策略的那个物品，选后再检查
	idx = spFunc(problem.Objects, problem.totalC-ntc)
	log.Println("idx = ", idx)

	for idx != -1 {
		if ntc+problem.Objects[idx].weight <= problem.totalC {
			problem.Objects[idx].status = 1
			ntc += problem.Objects[idx].weight
		} else {
			// 不能选这个物品了，做个标记后重新选
			problem.Objects[idx].status = 2
		}

		// spFunc 每次选最符合策略的那个物品，选后再检查
		idx = spFunc(problem.Objects, problem.totalC-ntc)
	}

	log.Printf("%#v\n", problem.Objects)
}

func Choosefunc1(objs []*Object, c int) int {
	log.Println(len(objs))
	index := -1
	mp := 0
	for i := 0; i < len(objs); i++ {
		if objs[i].status == 0 && objs[i].price > mp {
			mp = objs[i].price
			index = i
		}
	}
	log.Println("index = ", index)
	return index
}
