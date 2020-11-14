#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _sky, _grass, _mountes, _cloud, _cloud2, _sun, _road, _car, _tree, _column, _sign, _stone;
	int _width_cloud, _width_sun,
		_sky_x, _sky_x2,
		_sun_x, _sun_y,
		_cloud_x_up, _cloud_x_up2, _cloud_x_up3,
		_cloud_x_up4, _cloud_x_up5, _cloud_x_up6,
		_sky_y, _grass_y, _mountes_y, _cloud_y,
		_step_slow, _step_cloud, _step_sun, _step_tree,
		_road_x, _road_x2, _road_y,
		_car_x, _car_y, _step_fast, _tree_x, _tree_x2, _tree_y,
		_column_x, _column_x2, _column_x3, _column_x4,
		_column_x1, _column_x12, _column_x13, _column_x14,
		_column_y, _column_y1,
		_sign_x, _sign_y,
		_stone_x, _stone_x2, _stone_y;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};


#endif /* EXAMPLEWINDOW_H_ */
