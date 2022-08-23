email = "example@ukr.net"

if '@' in email and '.' in email and email.index('.') > email.index('@'):
    if len(email[email.index('.'):]) > 2:
        print("Коректно")