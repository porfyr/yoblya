package main

import (
	"log"

	tgbotapi "github.com/Syfaro/telegram-bot-api"
)

func reply_markup() (
	knopka := tgbotapi.KeyboardButton{
		"Так!", false, false, *KeyboardButtonPollType{""}, WebAppInfo{""}
	}

	itemsSel := [][]tgbotapi.KeyboardButton{knopka}
	itemsSel = append(itemsSel, []tgbotapi.KeyboardButton{})
	msg := tgbotapi.NewMessage(update.Message.Chat.ID, "Select item")

	msg.ReplyMarkup = &tgbotapi.ReplyKeyboardMarkup{
		Keyboard:        itemsSel,
		ResizeKeyboard:  true,
		OneTimeKeyboard: false,
		Selective:       false,
	
	log.Println(msg.ReplyMarkup)
	msg.ReplyToMessageID = update.Message.MessageID
	_, err = bot.Send(msg)
)

func main() {
	bot, err := tgbotapi.NewBotAPI("5398006535:AAH8hKDzC-2amQezgtJ0MWZWl8oyqCXEsIU")
	if err != nil {
		log.Panic(err) // log ------------------__________
	}

	bot.Debug = true

	log.Printf("Authorized on account %s", bot.Self.UserName)

	u := tgbotapi.NewUpdate(0)
	u.Timeout = 60

	updates, _ := bot.GetUpdatesChan(u)

	for update := range updates {
		if update.Message != nil { // If we got a message

			
			
		}
	}
}

/*


	Шаблон відповіді на повідомлення
			msg := tgbotapi.NewMessage(update.Message.Chat.ID, update.Message.Text)
			msg.ReplyToMessageID = update.Message.MessageID
			bot.Send(msg)


func main() {
	bot, err := tgbotapi.NewBotAPI("5398006535:AAH8hKDzC-2amQezgtJ0MWZWl8oyqCXEsIU")
	if err != nil {
		log.Panic(err) // log ------------------__________
	}

	bot.Debug = true

	log.Printf("Authorized on account %s", bot.Self.UserName)

	u := tgbotapi.NewUpdate(0)
	u.Timeout = 60

	updates, _ := bot.GetUpdatesChan(u)

	for update := range updates {
		if update.Message != nil { // If we got a message
			log.Printf("[%s] %s", update.Message.From.UserName, update.Message.Text)

			msg := tgbotapi.NewMessage(update.Message.Chat.ID, update.Message.Text)
			msg.ReplyToMessageID = update.Message.MessageID

			bot.Send(msg)
		}
	}
}

*/
