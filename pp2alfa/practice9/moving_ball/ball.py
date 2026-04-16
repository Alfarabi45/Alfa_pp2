import pygame

class Ball:
    def __init__(self, x, y, radius, step, screen_width, screen_height):
        self.x = x
        self.y = y
        self.radius = radius
        self.step = step
        self.screen_width = screen_width
        self.screen_height = screen_height
        self.color = (255, 0, 0)

    def move(self, direction):
        if direction == "LEFT":
            if self.x - self.step - self.radius >= 0:
                self.x -= self.step

        elif direction == "RIGHT":
            if self.x + self.step + self.radius <= self.screen_width:
                self.x += self.step

        elif direction == "UP":
            if self.y - self.step - self.radius >= 0:
                self.y -= self.step

        elif direction == "DOWN":
            if self.y + self.step + self.radius <= self.screen_height:
                self.y += self.step

    def draw(self, screen):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius)