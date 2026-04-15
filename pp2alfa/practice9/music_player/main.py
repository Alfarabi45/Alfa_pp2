import pygame
from player import MusicPlayer

pygame.init()
screen = pygame.display.set_mode((600, 400))
pygame.display.set_caption("Music Player")

player = MusicPlayer()

running = True
font = pygame.font.SysFont(None, 36)

while running:
    screen.fill((0, 0, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_p:
                player.play()
            elif event.key == pygame.K_s:
                player.stop()
            elif event.key == pygame.K_n:
                player.next()
            elif event.key == pygame.K_b:
                player.prev()
            elif event.key == pygame.K_q:
                running = False

    text = font.render(player.current_track(), True, (255, 255, 255))
    screen.blit(text, (50, 150))

    pygame.display.flip()

pygame.quit()