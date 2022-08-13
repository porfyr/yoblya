package main

import (
	"net/http"
	"io/ioutil"
	"encoding/json"
	"log"
	"fmt"
	"bytes"
	"strconv"
)

func main() {
	botToken := "5581386690:AAEEJ_N3o0tWU1yMTKpRQg5tvbr_EtmT7jU"
	// https://api.telegram.org/bot<token>/METHOD_NAME
	botAPI := "https://api.telegram.org/bot"
	botURL := botAPI + botToken
	offset := 0
	for ;; {
		updates , err := getUpdates(botURL, offset)
		if err != nil {
			log.Println("Щось пішло по пизді: ", err.Error())
		}
		for _, update := range updates {
			err = respond(botURL, update)
			offset = update.UpdateID + 1
		}
		fmt.Println(updates)
	}
}

func getUpdates(botURL string, offset int) ([]Update, error) {
	resp, err := http.Get(botURL + "/getUpdates" + "?offset=" + strconv.Itoa(offset))
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}
	var restResponse RestResponse
	err = json.Unmarshal(body, &restResponse)
	if err != nil {
		return nil, err
	}
	return restResponse.Result, nil
}

func respond(botURL string, update Update) (error) {
	var botMessage BotMessage
	botMessage.ChatID = update.Message.Chat.ChatID
	botMessage.Text = update.Message.Text
	buf, err := json.Marshal(botMessage)
	if err != nil {
		return err
	}
	_, err = http.Post(botURL + "/sendMessage", "application/json", bytes.NewBuffer(buf))
	if err != nil {
		return err
	}
	return nil
}