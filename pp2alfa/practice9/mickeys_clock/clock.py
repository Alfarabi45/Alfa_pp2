import pygame
import datetime
import math

class MickeyClock:
    def __init__(self, center):
        self.center = center

        
        self.sec_hand = self.create_hand((255, 0, 0), 180, 6)   
        self.min_hand = self.create_hand((0, 0, 0), 140, 8)    

    def create_hand(self, color, length, width):
        surface = pygame.Surface((width, length), pygame.SRCALPHA)
        pygame.draw.rect(surface, color, (0, 0, width, length))
        return surface

    def get_time_angles(self):
        now = datetime.datetime.now()
        seconds = now.second
        minutes = now.minute

        sec_angle = -seconds * 6
        min_angle = -minutes * 6

        return sec_angle, min_angle

    def draw_hand(self, screen, hand, angle):
        rotated = pygame.transform.rotate(hand, angle)
        rect = rotated.get_rect(center=self.center)
        screen.blit(rotated, rect)

    def draw(self, screen):
        sec_angle, min_angle = self.get_time_angles()

        self.draw_hand(screen, self.min_hand, min_angle)
        self.draw_hand(screen, self.sec_hand, sec_angle)