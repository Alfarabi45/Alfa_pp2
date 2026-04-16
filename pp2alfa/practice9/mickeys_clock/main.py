import pygame
import sys
from clock import MickeyClock

pygame.init()

WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Mickey's Clock")

clock = pygame.time.Clock()


center = (WIDTH // 2, HEIGHT // 2)


import os

base_path = os.path.dirname(__file__)
image_path = os.path.join(base_path, "images", "mickey_hand.png")

mickey = MickeyClock(center, image_path)
running = True
while running:
    clock.tick(1)  

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((255, 255, 255))

    
    mickey.draw(screen)

    pygame.display.flip()

pygame.quit()
sys.exit()