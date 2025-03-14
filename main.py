import serial
import asyncio
import websockets

ser = serial.Serial("COM5", 115200, timeout=1)

async def send_data(websocket, path):
    try:
        while True:
            data = ser.readline().decode().strip() 
            if data:
             #   print(f"📡 Gelen Veri: {data}")  
                await websocket.send(data)  
            await asyncio.sleep(0.05) 
    except Exception as e:
        print("❌ Hata:", e)

async def main():
    print("WebSocket başlatılıyor...")
    async with websockets.serve(send_data, "0.0.0.0", 8765):
        print("WebSocket çalışıyor!")
        await asyncio.Future() 
asyncio.run(main())
