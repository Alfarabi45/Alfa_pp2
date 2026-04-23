import pygame
import sys
import math

pygame.init()

WIDTH, HEIGHT = 900, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Advanced Paint")

clock = pygame.time.Clock()

WHITE = (255,255,255)
BLACK = (0,0,0)
RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
GRAY = (200,200,200)

canvas = pygame.Surface((WIDTH, HEIGHT))
canvas.fill(WHITE)

color = BLACK
mode = "draw"
drawing = False
start_pos = None
last_pos = None

buttons = [
    ("Draw", 10, 10, "draw"),
    ("Rect", 80, 10, "rect"),
    ("Circle", 150, 10, "circle"),
    ("Erase", 240, 10, "erase"),
]

colors = [
    (RED, 350),
    (GREEN, 390),
    (BLUE, 430),
    (BLACK, 470)
]

font = pygame.font.SysFont("Verdana", 18)

def draw_ui():
    for text, x, y, m in buttons:
        pygame.draw.rect(screen, GRAY, (x, y, 60, 30))
        label = font.render(text, True, BLACK)
        screen.blit(label, (x+5, y+5))

    for c, x in colors:
        pygame.draw.rect(screen, c, (x, 10, 30, 30))

def draw_line(surface, color, start, end, width=5):
    dx = end[0] - start[0]
    dy = end[1] - start[1]
    dist = max(abs(dx), abs(dy))
    for i in range(dist):
        x = int(start[0] + float(i)/dist * dx)
        y = int(start[1] + float(i)/dist * dy)
        pygame.draw.circle(surface, color, (x,y), width)

while True:
    screen.fill(WHITE)
    screen.blit(canvas, (0,0))
    draw_ui()

    mouse_pos = pygame.mouse.get_pos()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.MOUSEBUTTONDOWN:
            drawing = True
            start_pos = event.pos
            last_pos = event.pos

            x, y = event.pos

            for text, bx, by, m in buttons:
                if bx <= x <= bx+60 and by <= y <= by+30:
                    mode = m

            for c, cx in colors:
                if cx <= x <= cx+30 and 10 <= y <= 40:
                    color = c

        if event.type == pygame.MOUSEBUTTONUP:
            drawing = False

            if mode == "rect":
                x1, y1 = start_pos
                x2, y2 = event.pos
                rect = pygame.Rect(min(x1,x2), min(y1,y2), abs(x2-x1), abs(y2-y1))
                pygame.draw.rect(canvas, color, rect, 2)

            elif mode == "circle":
                radius = int(math.hypot(event.pos[0]-start_pos[0], event.pos[1]-start_pos[1]))
                pygame.draw.circle(canvas, color, start_pos, radius, 2)

    if drawing:
        if mode == "draw":
            draw_line(canvas, color, last_pos, mouse_pos, 4)
            last_pos = mouse_pos

        elif mode == "erase":
            draw_line(canvas, WHITE, last_pos, mouse_pos, 10)
            last_pos = mouse_pos

    if drawing and mode in ["rect", "circle"]:
        preview = canvas.copy()

        if mode == "rect":
            x1, y1 = start_pos
            x2, y2 = mouse_pos
            rect = pygame.Rect(min(x1,x2), min(y1,y2), abs(x2-x1), abs(y2-y1))
            pygame.draw.rect(preview, color, rect, 2)

        elif mode == "circle":
            radius = int(math.hypot(mouse_pos[0]-start_pos[0], mouse_pos[1]-start_pos[1]))
            pygame.draw.circle(preview, color, start_pos, radius, 2)

        screen.blit(preview, (0,0))

    pygame.display.update()
    clock.tick(60)