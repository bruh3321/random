from interactions import Client, SlashContext, slash_command, events
import random

import interactions
from token_serverID import bot_token

bot = Client(token=bot_token, intents = interactions.Intents.DEFAULT | interactions.Intents.ALL)

@bot.listen()
async def on_startup():
    print("Bot started")

@slash_command(name="number_guess", description="Start a number guessing game.")
async def number_guess(ctx: SlashContext):
    def check_channel(msg: events.MessageCreate):
        return ctx.channel.id == msg.message.channel.id and msg.message.content.isdigit()

    x = random.randint(0, 100)
    print(x)
    await ctx.send("Number generated between 0 and 100. Send messages, and I'll say 'higher' or 'lower'. You have 1 minute.")
    
    try:
        msg = False
        while True:
            msg = await bot.wait_for(event=events.MessageCreate, checks=check_channel, timeout=60)#type: ignore
            if int(msg.message.content) > x:
                await ctx.send("Guess lower!")
            elif int(msg.message.content) < x:
                await ctx.send("Guess higher!")
            elif int(msg.message.content) == x:
                return await ctx.send(f"Congratulations! You guessed it right! It was {x}.")
    except Exception as e:
        print(e)
        return await ctx.send(f"Timeout! The number was {x}.")
bot.start()
