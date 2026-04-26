import pygame
import sys
import math

pygame.init()

# -------------------- WINDOW SETTINGS --------------------
WIDTH, HEIGHT = 900, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Advanced Paint")

clock = pygame.time.Clock()

# -------------------- COLORS --------------------
WHITE = (255,255,255)
BLACK = (0,0,0)
RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
GRAY = (200,200,200)

# -------------------- CANVAS --------------------
canvas = pygame.Surface((WIDTH, HEIGHT))
canvas.fill(WHITE)

color = BLACK
mode = "draw"
drawing = False
start_pos = None
last_pos = None

# -------------------- UI BUTTONS --------------------
buttons = [
    ("Draw", 10, 10, "draw"),
    ("Rect", 80, 10, "rect"),
    ("Circle", 150, 10, "circle"),
    ("Square", 230, 10, "square"),
    ("R-Tri", 320, 10, "rtriangle"),
    ("Eq-Tri", 400, 10, "eqtriangle"),
    ("Rhomb", 490, 10, "rhombus"),
    ("Erase", 600, 10, "erase"),
]

colors = [
    (RED, 720),
    (GREEN, 760),
    (BLUE, 800),
    (BLACK, 840)
]

font = pygame.font.SysFont("Verdana", 18)

# -------------------- UI DRAW --------------------
def draw_ui():
    for text, x, y, m in buttons:
        pygame.draw.rect(screen, GRAY, (x, y, 70, 30))
        label = font.render(text, True, BLACK)
        screen.blit(label, (x+3, y+5))

    for c, x in colors:
        pygame.draw.rect(screen, c, (x, 10, 30, 30))

# -------------------- LINE TOOL --------------------
def draw_line(surface, color, start, end, width=5):
    dx = end[0] - start[0]
    dy = end[1] - start[1]
    dist = max(abs(dx), abs(dy))
    if dist == 0:
        return
    for i in range(dist):
        x = int(start[0] + i/dist * dx)
        y = int(start[1] + i/dist * dy)
        pygame.draw.circle(surface, color, (x,y), width)

# -------------------- MAIN LOOP --------------------
while True:
    screen.fill(WHITE)
    screen.blit(canvas, (0,0))
    draw_ui()

    mouse_pos = pygame.mouse.get_pos()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        # -------------------- MOUSE DOWN --------------------
        if event.type == pygame.MOUSEBUTTONDOWN:
            drawing = True
            start_pos = event.pos
            last_pos = event.pos

            x, y = event.pos

            # check buttons
            for text, bx, by, m in buttons:
                if bx <= x <= bx+70 and by <= y <= by+30:
                    mode = m

            # check colors
            for c, cx in colors:
                if cx <= x <= cx+30 and 10 <= y <= 40:
                    color = c

        # -------------------- MOUSE UP --------------------
        if event.type == pygame.MOUSEBUTTONUP:
            drawing = False
            x1, y1 = start_pos
            x2, y2 = event.pos

            # RECTANGLE
            if mode == "rect":
                rect = pygame.Rect(min(x1,x2), min(y1,y2), abs(x2-x1), abs(y2-y1))
                pygame.draw.rect(canvas, color, rect, 2)

            # CIRCLE
            elif mode == "circle":
                radius = int(math.hypot(x2-x1, y2-y1))
                pygame.draw.circle(canvas, color, start_pos, radius, 2)

            # SQUARE
            elif mode == "square":
                side = min(abs(x2-x1), abs(y2-y1))
                rect = pygame.Rect(x1, y1, side, side)
                pygame.draw.rect(canvas, color, rect, 2)

            # RIGHT TRIANGLE
            elif mode == "rtriangle":
                points = [(x1,y1), (x2,y1), (x2,y2)]
                pygame.draw.polygon(canvas, color, points, 2)

            # EQUILATERAL TRIANGLE
            elif mode == "eqtriangle":
                side = math.hypot(x2-x1, y2-y1)
                height = (math.sqrt(3)/2) * side
                p1 = (x1, y1)
                p2 = (x2, y2)
                p3 = (x1, y1 - height)
                pygame.draw.polygon(canvas, color, [p1,p2,p3], 2)

            # RHOMBUS (diamond)
            elif mode == "rhombus":
                mx, my = (x1+x2)//2, (y1+y2)//2
                dx, dy = abs(x2-x1)//2, abs(y2-y1)//2
                points = [
                    (mx, my-dy),
                    (mx+dx, my),
                    (mx, my+dy),
                    (mx-dx, my)
                ]
                pygame.draw.polygon(canvas, color, points, 2)

    # -------------------- FREE DRAW / ERASE --------------------
    if drawing:
        if mode == "draw":
            draw_line(canvas, color, last_pos, mouse_pos, 4)
            last_pos = mouse_pos

        elif mode == "erase":
            draw_line(canvas, WHITE, last_pos, mouse_pos, 10)
            last_pos = mouse_pos

    # -------------------- PREVIEW SHAPES --------------------
    if drawing and mode in ["rect","circle","square","rtriangle","eqtriangle","rhombus"]:
        preview = canvas.copy()
        x1,y1 = start_pos
        x2,y2 = mouse_pos

        if mode == "rect":
            rect = pygame.Rect(min(x1,x2), min(y1,y2), abs(x2-x1), abs(y2-y1))
            pygame.draw.rect(preview, color, rect, 2)

        elif mode == "circle":
            radius = int(math.hypot(x2-x1, y2-y1))
            pygame.draw.circle(preview, color, start_pos, radius, 2)

        elif mode == "square":
            side = min(abs(x2-x1), abs(y2-y1))
            pygame.draw.rect(preview, color, pygame.Rect(x1,y1,side,side), 2)

        elif mode == "rtriangle":
            pygame.draw.polygon(preview, color, [(x1,y1),(x2,y1),(x2,y2)], 2)

        elif mode == "eqtriangle":
            side = math.hypot(x2-x1, y2-y1)
            height = (math.sqrt(3)/2) * side
            pygame.draw.polygon(preview, color, [(x1,y1),(x2,y2),(x1,y1-height)], 2)

        elif mode == "rhombus":
            mx, my = (x1+x2)//2, (y1+y2)//2
            dx, dy = abs(x2-x1)//2, abs(y2-y1)//2
            points = [
                (mx, my-dy),
                (mx+dx, my),
                (mx, my+dy),
                (mx-dx, my)
            ]
            pygame.draw.polygon(preview, color, points, 2)

        screen.blit(preview, (0,0))

    pygame.display.update()
    clock.tick(60)