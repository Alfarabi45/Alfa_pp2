import pygame
import sys
from ball import Ball

# Initialize pygame
pygame.init()

# Screen settings
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Moving Ball Game")

# Colors
WHITE = (255, 255, 255)

# Create ball
ball = Ball(
    x=WIDTH // 2,
    y=HEIGHT // 2,
    radius=25,
    step=20,
    screen_width=WIDTH,
    screen_height=HEIGHT
)

# Clock
clock = pygame.time.Clock()

# Game loop
running = True
while running:
    clock.tick(60)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                ball.move("LEFT")
            elif event.key == pygame.K_RIGHT:
                ball.move("RIGHT")
            elif event.key == pygame.K_UP:
                ball.move("UP")
            elif event.key == pygame.K_DOWN:
                ball.move("DOWN")

    # Draw
    screen.fill(WHITE)
    ball.draw(screen)

    pygame.display.flip()

pygame.quit()
sys.exit()