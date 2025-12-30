from collections import deque
import asyncio

datos = "1101.1011..0110.1110.01..1011.0.110"

CAPACITY = 5
WARMUP = 3
INTERVALO_PLAYER = 0.15
INTERVALO_NET = 0.12

buffer = deque(maxlen=CAPACITY)
next_id = 0
reconectado = False

producer_finished = False

def log_net(msg):
    print(f"[NET] {msg}")

def log_player(msg):
    print(f"[PLAYER] {msg}")

def log_recov(msg):
    print(f"[RECOVERY] {msg}")

async def productor(datos):
    global next_id, reconectado

    for s in datos:
        await asyncio.sleep(INTERVALO_NET)

        if s in ("0", "1"):
            next_id += 1

            if reconectado:
                log_net("Reconectado | rellenando...")
                reconectado = False
            
            buffer.append(next_id)
            log_net(f"Chunk recibido #{next_id} | buffer={len(buffer)}/{CAPACITY}")
        
        else:
            log_net("OFFLINE")
            reconectado = True

    global producer_finished
