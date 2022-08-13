package main

import (
	"log"

	tgbotapi "github.com/Syfaro/telegram-bot-api"
)

func main() {
	bot, err := tgbotapi.NewBotAPI("5398006535:AAH8hKDzC-2amQezgtJ0MWZWl8oyqCXEsIU")
	if err != nil {
		log.Panic(err) // log ------------------__________
	}

	bot.Debug = true

	log.Printf("Authorized on account %s", bot.Self.UserName) // log ----------------------------

	u := tgbotapi.NewUpdate(0)
	u.Timeout = 60

	updates, _ := bot.GetUpdatesChan(u)

	for update := range updates {
		if update.Message.Text != nil { // If we got a message
			if 
		}
	}
}

/*


	Шаблон відповіді на повідомлення
			msg := tgbotapi.NewMessage(update.Message.Chat.ID, update.Message.Text)
			msg.ReplyToMessageID = update.Message.MessageID
			bot.Send(msg)


*/
