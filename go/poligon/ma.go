package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	//"github.com/tidwall/gjson"
)

type pasazhyr struct {
	Imja     string `json:"name"`
	Sigarety string `json:"sigarety"`
	Blocky   int    `json:"blocky"`
}

func main() {

	Ivan := pasazhyr{"Йован", "Харвес", 3}

	file, _ := json.MarshalIndent(Ivan, "", " ")

	_ = ioutil.WriteFile("he.json", file, 0644)

	fmt.Printf("%v %T", file, file)

	fmt.Println("\n_______________\n   ok computer ")
}

/*






	[{"name":"Женя","sigarety":"Марльборо","blocky":3},{"name":"Місько","sigarety":"Харвес","blocky":6}]

*/
