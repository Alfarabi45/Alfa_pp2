import pygame
import math
import datetime

pygame.init()

WIDTH, HEIGHT = 600, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Mickey Clock")

clock = pygame.time.Clock()

# Загружаем изображение руки
import os

base_path = os.path.dirname(__file__)
image_path = os.path.join(base_path, "images", "mickey_hand.png")

hand = pygame.image.load(image_path)
hand = pygame.transform.scale(hand, (200, 50))

center = (WIDTH // 2, HEIGHT // 2)

def rotate_hand(image, angle):
    return pygame.transform.rotate(image, angle)

running = True
while running:
    screen.fill((255, 255, 255))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    now = datetime.datetime.now()
    seconds = now.second
    minutes = now.minute

    sec_angle = -seconds * 6     # 360/60 = 6
    min_angle = -minutes * 6

    sec_hand = rotate_hand(hand, sec_angle)
    min_hand = rotate_hand(hand, min_angle)

    sec_rect = sec_hand.get_rect(center=center)
    min_rect = min_hand.get_rect(center=center)

    screen.blit(min_hand, min_rect)
    screen.blit(sec_hand, sec_rect)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()