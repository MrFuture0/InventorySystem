# InventorySystem
inventory system with c++ on 4.27.2
Food items: If a food item already exists in the inventory and the player tries to pick it up again, the system increases its quantity and keeps it in stock. Consuming the food item removes it from the inventory, and when the stock count reaches zero, it disappears completely. Additionally, consuming a food item restores +HP to the player's health.

Vest and helmet: If a vest or helmet is already in the inventory and the player attempts to pick it up again, it replenishes their health to 100. Moreover, when the player's health reaches zero, the vest or helmet breaks, adding a layer of realism and challenge. Also, if the player no longer possesses a vest or helmet, it will be removed from the inventory.
