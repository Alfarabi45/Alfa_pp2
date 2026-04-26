import pygame
import sys
import random

pygame.init()

# -------------------- SETTINGS --------------------
WIDTH, HEIGHT = 600, 400
CELL_SIZE = 20

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake Game")

clock = pygame.time.Clock()

# -------------------- COLORS --------------------
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 200, 0)
RED = (200, 0, 0)
YELLOW = (255, 200, 0)
BLUE = (0, 120, 255)

font = pygame.font.SysFont("Verdana", 24)

# -------------------- SNAKE --------------------
snake = [(100, 100), (80, 100), (60, 100)]
direction = (CELL_SIZE, 0)

# -------------------- FOOD SYSTEM --------------------
def generate_food():
    """Generate food in random position not inside snake"""
    x = random.randint(0, (WIDTH - CELL_SIZE) // CELL_SIZE) * CELL_SIZE
    y = random.randint(0, (HEIGHT - CELL_SIZE) // CELL_SIZE) * CELL_SIZE
    return (x, y)

food = generate_food()
food_spawn_time = pygame.time.get_ticks()
food_lifetime = 5000  # 5 seconds

# food types (weight system)
food_types = [
    (RED, 1),
    (YELLOW, 2),
    (BLUE, 3)
]

current_food_type = random.choice(food_types)

# -------------------- GAME STATS --------------------
score = 0
level = 1
foods_to_next_level = 3
speed = 7

# -------------------- DRAW FUNCTIONS --------------------
def draw_snake():
    """Draw snake on screen"""
    for i, block in enumerate(snake):
        color = (0, 255, 0) if i == 0 else (0, 150, 0)
        pygame.draw.rect(screen, color, (block[0], block[1], CELL_SIZE, CELL_SIZE))

def draw_food():
    """Draw food with different weight color"""
    color, _ = current_food_type
    pygame.draw.rect(screen, color, (food[0], food[1], CELL_SIZE, CELL_SIZE))

def check_wall_collision(head):
    """Check collision with walls"""
    return head[0] < 0 or head[0] >= WIDTH or head[1] < 0 or head[1] >= HEIGHT

def check_self_collision(head):
    """Check collision with itself"""
    return head in snake[1:]

# -------------------- GAME LOOP --------------------
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        # -------------------- CONTROLS --------------------
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP and direction != (0, CELL_SIZE):
                direction = (0, -CELL_SIZE)
            elif event.key == pygame.K_DOWN and direction != (0, -CELL_SIZE):
                direction = (0, CELL_SIZE)
            elif event.key == pygame.K_LEFT and direction != (CELL_SIZE, 0):
                direction = (-CELL_SIZE, 0)
            elif event.key == pygame.K_RIGHT and direction != (-CELL_SIZE, 0):
                direction = (CELL_SIZE, 0)

    # -------------------- MOVE SNAKE --------------------
    head_x, head_y = snake[0]
    new_head = (head_x + direction[0], head_y + direction[1])

    if check_wall_collision(new_head) or check_self_collision(new_head):
        pygame.quit()
        sys.exit()

    snake.insert(0, new_head)

    # -------------------- FOOD EATING --------------------
    if new_head == food:
        _, weight = current_food_type  # food score weight
        score += weight

        foods_to_next_level -= 1

        food = generate_food()
        food_spawn_time = pygame.time.get_ticks()
        current_food_type = random.choice(food_types)
    else:
        snake.pop()

    # -------------------- LEVEL SYSTEM --------------------
    if foods_to_next_level == 0:
        level += 1
        foods_to_next_level = 3
        speed += 1

    # -------------------- FOOD TIMER (DISAPPEAR) --------------------
    if pygame.time.get_ticks() - food_spawn_time > food_lifetime:
        food = generate_food()
        food_spawn_time = pygame.time.get_ticks()
        current_food_type = random.choice(food_types)

    # -------------------- DRAW --------------------
    screen.fill(BLACK)

    draw_snake()
    draw_food()

    # UI TEXT
    screen.blit(font.render(f"Score: {score}", True, WHITE), (10, 10))
    screen.blit(font.render(f"Level: {level}", True, WHITE), (10, 40))

    pygame.display.update()
    clock.tick(speed)